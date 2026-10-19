# C++ 입문 1 (S1 3주차)

## 구조체와 열거형 (10-14)
EMG 채널 2개를 구조체 배열로, 그리퍼 상태를 열거형으로 만들어 출력했다(OnlineGDB, C++).

```cpp
struct EmgChannel {      // 관련 데이터를 한 묶음으로
    int   pin;
    int   raw;
    float rms;
};

enum GripState { IDLE, CLOSING, HOLDING, OPENING };
```
- pin 14·15는 Nano의 A0·A1이다.
- `stateName()`의 `switch`로 상태 번호를 이름으로 바꿔 출력했다. 출력: IDLE 0, CLOSING 1, HOLDING 2, OPENING 3.

### 내 말로
- 구조체는 함께 묶이는 데이터를 하나의 타입으로 묶어서 쉽게 접근하고 수정할 수 있게 한다.
  - (교정) 숫자만이 아니라 서로 다른 타입(int, float, 배열, 다른 구조체)을 함께 묶을 수 있다. 위 예제도 int와 float를 섞었다.
- 열거형은 숫자 대신 이름으로 써서 코드를 읽기 쉽게 한다. 열거형 정의 자체에는 메모리가 할당되지 않는다.
  - (교정) 정의에는 메모리가 없지만, `GripState s;`처럼 변수를 만들면 int 크기의 메모리를 쓴다(PC 4바이트, Nano 2바이트).
  - (교정) 이유 하나 더: 쓸 수 있는 값을 정해진 상태로 제한한다. `switch`에서 상태 하나를 빠뜨리면 컴파일러가 경고해(-Wall) 상태기계 실수를 막아 준다.

## 클래스·참조·Arduino 구조 (10-16)

### 오늘 한 것
- EmgChannel을 class로 바꾸고 read()·print() 작성, private 접근 오류 확인
- swap 포인터 버전 vs 참조 버전 나란히 실행, const 참조로 객체 넘기기
- .ino가 C++로 빌드되는 구조를 PC에서 흉내 내 실행

### 클래스
- 생성자: 클래스 이름과 같고 반환형이 없음. 객체를 만들 때 자동으로 한 번 실행
  - `EmgChannel(int p) : pin(p), value(0) {}` → `: 멤버(초기값)`은 초기화 리스트
  - 본문에서 대입해도 지금은 같게 동작. const·참조 멤버는 리스트로만 초기화 가능 (나중에)
- 생성자를 안 만들면 컴파일러가 기본 생성자를 만들어 주지만 int 멤버는 0이 보장되지 않음 (쓰레기 값)
- 인자 있는 생성자를 직접 만들면 기본 생성자가 사라짐 → `EmgChannel ch;`, `EmgChannel ch[2];` 오류
  - 배열은 `{ EmgChannel(14), EmgChannel(15) }`처럼 인자를 직접 넘김
- private 멤버 접근 오류 메시지: `'int EmgChannel::value' is private within this context`
- class에서 접근 지정자를 모두 지우면 생성자까지 private → 객체 생성부터 막힘
- 클래스 밖의 일반 함수(printChannel 등)는 접근 지정자 대상이 아님. 단, 받은 객체의 public 멤버만 사용 가능

### const
- const = 읽기 전용. 이 이름으로는 바꿀 수 없다는 뜻 (원본 자체가 상수가 되는 건 아님)
- `print() const` 안에서
  - 멤버에 대입 → 컴파일 오류
  - 새 지역 변수 선언 → 문제없음
  - 멤버와 같은 이름의 지역 변수 → 컴파일은 되지만 멤버를 가림(shadowing), 피할 것
- const 객체·const 참조에서는 const 멤버 함수만 호출 가능
  - 그래서 print()에서 const를 지우면 printChannel(const EmgChannel &)에서 오류
- 실행 중에 정해지는 값도 const 가능. 컴파일 시점 상수는 constexpr (이름만)

### 참조
- 실험 결과: swapRef 안의 &a == main의 &x → 복사본이 아니라 같은 메모리
- printChannel(const 참조)의 &ch == main의 &ch, printCopy(값)의 &ch는 다름 → 값 전달은 객체 전체 복사
- 읽기만 할 객체는 `const 타입 &`로 넘기는 것이 기본 습관 (Nano SRAM 2KB에서 복사 비용 절약)
- `int &r;` → 오류. 참조는 선언과 동시에 대상이 필요
- `int &r = x; r = y;` → x에 y의 값이 대입될 뿐, r은 계속 x를 가리킴 (출력 2 2)

| 기호 | 선언에서 (타입 옆) | 식에서 (값 앞) |
|---|---|---|
| & | `int &a` 참조 | `&x` 주소를 구함 |
| * | `int *p` 포인터 | `*p` 가리키는 값 |

### 객체의 메모리
- 객체 = 멤버 변수가 선언 순서대로 이어 붙은 덩어리. 객체 주소 = 시작 주소 = 첫 멤버 주소 (단순한 클래스 기준)
- 멤버 함수는 객체 메모리를 차지하지 않음 (sizeof(EmgChannel) = int 2개)
- `ch.read()` 호출 시 객체 주소가 숨은 인자 `this`로 전달됨
- 멤버 사이에 패딩이 생겨 sizeof가 멤버 합보다 커질 수 있음 (이름만)
- PC: EmgChannel 8바이트 / Nano(int 2바이트): 4바이트 → 2채널이면 16 / 8바이트

### Arduino 코드가 C++인 이유
- 빌드 전 .ino → .cpp 변환: `#include <Arduino.h>` 추가, 함수 원형 자동 생성, 여러 탭 합치기
- avr-g++(C++ 컴파일러)로 컴파일 → .ino에서 클래스·참조·const 모두 사용 가능
- main()은 코어의 main.cpp에 숨어 있음: 초기화 → setup() 1번 → loop() 무한 반복
- Serial은 Nano의 하드웨어 UART를 담당, USB-시리얼 칩을 거쳐 PC 시리얼 모니터와 연결
- begin(9600) = 9600 bps. 시리얼 모니터 속도도 같게 맞춰야 글자가 안 깨짐
- println(int), println(const char*)처럼 이름이 같고 인자 타입만 다른 함수 = 함수 오버로딩

### 오개념 교정 기록
| 교정 전 | 교정 후 |
|---|---|
| struct는 접근 지정자가 public | 접근 지정자는 키워드, 기본으로 정해지는 건 접근 권한 |
| 참조는 다른 이름으로 바뀐 것 | 원본에 이름이 하나 더 붙은 것 |
| 식의 &는 주소를 가리킨다 | 주소를 구한다 (가리키는 건 포인터) |
| `int &r;`은 r이 정의된 적 없어서 오류 | 이 줄이 선언이고, 참조 대상이 없어서 오류 |
| .은 멤버 함수를 부르는 연산자 | 멤버(변수·함수) 접근 연산자 |

## 아직 모르는 것 / 다음에
- EmgChannel을 setup()/loop() 구조에 넣기 → Nano 검수(Blink) 후 MyoWare 테스트 스케치 뼈대로 진행
- Arduino IDE 자세한 출력으로 실제 .ino.cpp 파일 열어 보기 (Nano·IDE 환경에서)
