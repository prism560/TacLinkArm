# MCU 작동 원리 (클럭 · GPIO · ADC)

- 날짜: 2026-10-12 (S1 3주차)
- 보드: Arduino Nano (ATmega328P)

## 오늘 한 것
- Arduino 공식 문서 2개를 읽고 클럭·GPIO·ADC를 내 말로 정리했다.
  - [Digital Pins](https://docs.arduino.cc/learn/microcontrollers/digital-pins/)
  - [Analog Read Serial](https://docs.arduino.cc/tutorials/uno-rev3/AnalogReadSerial/)
  - 클럭 사양: [Arduino Nano](https://docs.arduino.cc/hardware/nano/) Tech Specs

## 클럭: 16MHz
Nano 보드에는 16MHz 클럭 소스가 있다. MCU는 1초에 1600만 번 뛰는 박자에 맞춰 동작하고, 대부분의 명령은 1~2박자 만에 처리된다. 한 박자는 62.5ns이다.
이 박자가 `millis()`·PWM·ADC 같은 모든 시간의 기준이므로, 코드 한 줄이 걸리는 시간과 센서를 1초에 몇 번 읽을 수 있는지(샘플링 속도)의 상한을 예측할 수 있다.

## GPIO: INPUT, OUTPUT, INPUT_PULLUP
GPIO는 general purpose input/output, 즉 범용 입출력을 뜻한다.
INPUT은 핀의 전압을 읽기만 하며, 아무것도 연결하지 않으면 HIGH와 LOW를 오간다. 이것을 플로팅이라 한다.
INPUT_PULLUP은 플로팅을 막기 위해 ATmega 내부 저항(20~50kΩ)으로 핀을 5V 쪽에 붙잡아 둔다. 그래서 스위치를 핀과 GND 사이에 연결하면 평소에는 HIGH, 누르면 LOW가 된다.
OUTPUT은 저임피던스 상태이다. ATmega 핀의 절대 최대 정격은 40mA이므로(실제로는 20mA 이하로 사용), 출력에 필요한 전류에 맞게 직렬 저항을 골라야 한다.

## ADC: 10비트, 0~1023
아두이노 안에는 ADC(Analog-to-Digital Converter)라는 회로가 있다. ADC는 0~5V의 전압을 0~1023(2^10 − 1)의 숫자로 바꾼다.
`analogRead()`는 핀 전압(0~5V)에 비례하는 값을 0~1023 사이의 `int`로 돌려준다. 예를 들어 2V를 읽으면 409를 돌려준다.
한 단계의 크기는 5V / 1024 ≈ 4.9mV이다.

## 아직 모르는 것
- 풀업으로 핀을 5V로 유지하는 원리를 회로이론에서 배운 것 같은데 기억이 잘 안 난다. 회로를 직접 그리고, 계산하고, 설명할 수 있으면 좋겠다.
- (코치 제안) 고임피던스·저임피던스가 정확히 무슨 뜻인지, 왜 입력은 고임피던스이고 출력은 저임피던스여야 하는지.

## Tinkercad 실습 (10-13 추가 예정)
- LED Blink / 버튼(INPUT_PULLUP) / PWM 밝기 조절 — 링크 또는 캡처