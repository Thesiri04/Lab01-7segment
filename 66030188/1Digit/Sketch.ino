// กำหนดขา Arduino ที่เชื่อมต่อกับแต่ละส่วนของ Seven Segment (Common Cathode)
// สำหรับ Common Cathode: 1 = เปิด (ON), 0 = ปิด (OFF)
const int segA = 19;
const int segB = 18;
const int segC = 5;
const int segD = 17;
const int segE = 16;
const int segF = 4;
const int segG = 0;

// อาร์เรย์สำหรับเก็บค่าสถานะของแต่ละ Segment เพื่อแสดงตัวเลข
// รูปแบบ: {A, B, C, D, E, F, G}
byte digits[10][7] = {
  // A  B  C  D  E  F  G
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // กำหนดขา Seven Segment ทั้งหมดเป็น OUTPUT
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  // ปิด Seven Segment ทั้งหมดในตอนเริ่มต้น (แสดงเป็นค่าว่าง)
  clearSevenSegment();
}

void loop() {
  // นับเลข 0 ถึง 9
  for (int i = 0; i <= 9; i++) { // เปลี่ยนจาก 'i = 1' เป็น 'i = 0' เพื่อเริ่มนับจาก 0
    displayDigit(i);
    delay(1000); // หน่วงเวลา 1 วินาที
  }

  delay(2000); // หน่วงเวลา 2 วินาทีก่อนเริ่มนับใหม่
}

// ฟังก์ชันสำหรับแสดงตัวเลขบน Seven Segment
void displayDigit(int digit) {
  digitalWrite(segA, digits[digit][0]);
  digitalWrite(segB, digits[digit][1]);
  digitalWrite(segC, digits[digit][2]);
  digitalWrite(segD, digits[digit][3]);
  digitalWrite(segE, digits[digit][4]);
  digitalWrite(segF, digits[digit][5]);
  digitalWrite(segG, digits[digit][6]);
}

// ฟังก์ชันสำหรับเคลียร์ Seven Segment (ปิดทุก Segment)
void clearSevenSegment() {
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}
