# fsr_led_map
- 배선: FSR 분압(FSR + 10kΩ, 위쪽 Nano 5V) → A0, LED(+저항) → D3(PWM)
- 동작: `map(v, 20, 988, 0, 255)` + `constrain` → 누를수록 LED가 밝아짐, 9600 baud로 `v  b` 출력
- 결과(2026-10): 실측 0~988, 단계적 밝기 변화 확인 — [notes/fsr_led.md](../../notes/fsr_led.md)
