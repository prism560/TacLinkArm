# MyoWare 2.0 체크리스트 (2026-10-20)
출처: SparkFun "Getting Started with the MyoWare 2.0 Muscle Sensor Ecosystem", MyoWare v2 Quick Start Guide

## 연결
- VIN은 Nano 5V에 연결 (VIN 허용 2.27~5.47V, ENV 출력은 0~VIN이라 5V면 ADC 0~1023과 맞음)
- GND는 GND끼리
- ENV는 A0 같은 아날로그 입력 핀(A0~A7)에 연결 (교정: 아날로그 입력은 ADC 핀이며 PWM 핀이 아님. PWM은 ~3·5·6·9·10·11 출력용)

## 부착
- 처음 센서 작동 확인까지는 이두근에 부착
- 가급적 제모 후 알코올로 가볍게 닦고 말린 뒤 부착
- 전극 뒷면을 제거한 뒤 근육에 부착 (전극은 1회용)
- REF·MID·END 위치가 아주 중요함: MID는 근육 중앙, END는 근육 끝쪽(근섬유 방향을 따라), REF는 팔꿈치 뼈처럼 근육이 아닌 떨어진 곳

## 전기 안전
- 데스크탑으로 작업하면 USB isolator를 반드시 사용, 노트북으로 작업하면 충전기를 연결하지 않음
- (교정) 노트북도 외부 모니터·충전 중인 USB 기기 등 벽 전원 장치와 연결된 상태면 절연이 깨짐 → 측정 중에는 모두 뺌
