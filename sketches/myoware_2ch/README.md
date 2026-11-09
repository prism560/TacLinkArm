# myoware_2ch
- 배선: MyoWare(1) ENV → A0(굴곡근), MyoWare(2) ENV → A1(신전근), 두 보드 VIN → Nano 5V, GND 공통, 노트북 배터리 전원
- 동작: 채널 전환 직후 첫 값을 버리고 `flex:<a0>,ext:<a1>` 출력, 약 100Hz, 115200 baud(Serial Plotter용)
- 결과(2026-11-04): 굽힘엔 A0, 젖힘엔 A1만 크게 오름 — [notes/myoware_2ch.md](../../notes/myoware_2ch.md)
