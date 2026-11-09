# TacLinkArm

근전도(sEMG) 신호로 로봇 그리퍼를 움직이고, 그리퍼가 느낀 압력을 진동으로 사용자에게 돌려주는 원격조작 로봇팔 프로젝트입니다. 학부생 단독 홈랩 개발이며, V1의 목표는 "근육 신호 → 그리퍼 → 압력 → 진동" 폐루프를 처음부터 끝까지 동작시키는 것입니다.

현재 단계: S1 (부품 소싱, MyoWare 테스트, 그리퍼 STL 선정, 기초 이론 학습)

## 문서

* [부품 목록 (BoM)](BoM.md)
* [빌드로그 #1: C 포인터](notes/c_pointers.md)
* [V1 기획서 목차](docs/proposal.md)
* [빌드로그 #2: MCU 작동 원리 (클럭·GPIO·ADC·PWM)](notes/mcu_basics.md)
* [빌드로그 #3: C++ 입문 1 (구조체·클래스·참조)](notes/cpp_basics.md)
* [2·3주차 복습 정리](notes/review_week2_3.md)
* [MyoWare 2.0 안전·연결 체크리스트](notes/myoware_checklist.md)
* [빌드로그 #4: 첫 핀 헤더 납땜](notes/soldering.md)
* [빌드로그 #5: FSR→LED](notes/fsr_led.md)
* [빌드로그 #6: MyoWare 1·2채널 첫 측정과 FSR→서보](buildlog/2026-11-05_week6.md)
* [MyoWare 2채널 측정표](notes/myoware_2ch.md)

진행 상황: S1 6주차 완료 (2026-11-09)

* 2주차: MCU 작동 원리(클럭·GPIO·ADC), Tinkercad LED·버튼·PWM 시뮬레이션, 부품 2차 주문
* 3주차: C++ 입문 1(구조체·열거형·클래스·const·참조), 부품 1·2차 전량 수령, 납땜 도구 준비
* 4주차: 부품 검수·Nano Blink, MyoWare 안전 수칙, 첫 핀 헤더 납땜(MyoWare·INA219 재작업 필요), Tinkercad FSR 분압, FSR→LED 실측(0~988)
* 5~6주차: MyoWare·INA219 헤더 재작업, FSR→서보 각도 매핑, MyoWare 1채널·2채널(굴곡근/신전근) ENV 측정
