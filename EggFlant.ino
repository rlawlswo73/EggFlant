#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int m1stp = 5;  //첫벗째 스텝모터의 stp를 5번핀에 연결합니다.
int m1dir = 4;  //첫번째 스텝모터의 dir를 4번핀에 연결합니다.
int m2stp = 6;  //두번째 스텝모터의 stp를 6번핀에 연결합니다.
int m2dir = 7;  //두번째 스텝모터의 dir을 7번핀에 연결합니다.
int a = 4;    // 나중에 속도 조절 가능하게 하기 11111111111
int b = 250;
int times = 0;
int button = 0;

unsigned long currentMillis = millis() - 1000;

void sW() {
  digitalWrite(m1dir, LOW);
  digitalWrite(m1stp, HIGH);  //각각의 stp를 HIGH로 합니다,
  delay(a);               //d밀리초만큼 대기한뒤
  digitalWrite(m1stp, LOW);  // stp를 LOW로 합니다.
  delay(a); // d밀리초만큼 대기합니다.
}

void sS() {
  digitalWrite(m1dir, HIGH);
  digitalWrite(m1stp, HIGH);  //각각의 stp를 HIGH로 합니다,
  delay(a);               //d밀리초만큼 대기한뒤
  digitalWrite(m1stp, LOW);  // stp를 LOW로 합니다.
  delay(a); // d밀리초만큼 대기합니다.
}

void sF() {
  digitalWrite(m1dir, LOW);
  digitalWrite(m2dir, LOW);
  digitalWrite(m1stp, LOW);  //각각의 stp를 HIGH로 합니다,
  digitalWrite(m2stp, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();
  pinMode(m1stp, OUTPUT);//m1stp를 출력으로 설정합니다.
  pinMode(m1dir, OUTPUT);//m1dir을 출력으로 설정합니다.    
  pinMode(m2stp, OUTPUT);//m2stp를 출력으로 설정합니다.
  pinMode(m2dir, OUTPUT);//m2dir을 출력으로 설정합니다.
  digitalWrite(m1dir, LOW);
  digitalWrite(m2dir, LOW);
  digitalWrite(m1stp, LOW);  //각각의 stp를 HIGH로 합니다,
  digitalWrite(m2stp, LOW);

  // I2C_LCD를 초기화 해줍니다.
  lcd.init();
 
  // I2C_LCD의 백라이트를 켜줍니다.
  lcd.backlight();
 
  // 위에서 만든 특수문자를 0번 배열에 저장합니다.
//  lcd.createChar(0, customChar);

  lcd.setCursor(0, 0);
  lcd.print("minute / seconds");

}

const int upDown = currentMillis+1000;
const int leftRight = 6000;
const int Waiting = 3000;

void loop() {
  // put your main code here, to run repeatedly:
  if(currentMillis >= upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+upDown+100+leftRight) {
    currentMillis=currentMillis-upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+upDown+100+leftRight;
  }
  Serial.print("1:");
  Serial.println(currentMillis);
  while(currentMillis <= upDown && currentMillis > 0) {
    sS();
    Serial.print("2:");
    Serial.println(currentMillis);
    delay(1);
  }
  Serial.print("3:");
  Serial.println(currentMillis);
  while(currentMillis >= upDown+100 && currentMillis <= upDown+100+Waiting)  {
    lcd.setCursor(9, 1);
    lcd.print(3 - (currentMillis / 3000));
    Serial.print("4:");
    Serial.println(currentMillis);
    delay(1);
  }
  Serial.print("5:");
  Serial.println(currentMillis);
  while(currentMillis > upDown+100+Waiting+100 && currentMillis <= upDown+100+Waiting+100+upDown) {
    sW();
    Serial.print("6:");
    Serial.println(currentMillis);
    delay(1);
  }
//  Serial.println(currentMillis);
//  while(currentMillis > upDown+100+Waiting+100+upDown+100 && currentMillis <= upDown+100+Waiting+100+upDown+100+leftRight) {
//    digitalWrite(m2dir, LOW);
//    digitalWrite(m2stp, HIGH);  //각각의 stp를 HIGH로 합니다,
//    delayMicroseconds(b);               //d밀리초만큼 대기한뒤
//    digitalWrite(m2stp, LOW);  // stp를 LOW로 합니다.
//    delayMicroseconds(b);               //d밀리초만큼 대기한뒤
//    Serial.println(currentMillis);
//  }
//  Serial.println(currentMillis);
//  while(currentMillis > upDown+100+Waiting+100+upDown+100+leftRight+100 && currentMillis <= upDown+100+Waiting+100+upDown+100+leftRight+100+upDown) {
//    sS();
//    Serial.println(currentMillis);
//  }
//  Serial.println(currentMillis);
//  while(currentMillis > upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100 && currentMillis <= upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting) {
//    lcd.setCursor(8, 1);
//    lcd.print(3 - (currentMillis / 3000));
//    Serial.println(currentMillis);
//  }
//  Serial.println(currentMillis);
//  while(currentMillis > upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+100 && currentMillis <= upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+upDown) {
//    sW();  
//    Serial.println(currentMillis);
//  }
//  Serial.println(currentMillis);
//  while(currentMillis > upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+upDown+100 && currentMillis <= upDown+100+Waiting+100+upDown+100+leftRight+100+upDown+100+Waiting+upDown+100+leftRight) {
//    digitalWrite(m2dir, HIGH);
//    digitalWrite(m2stp, HIGH);  //각각의 stp를 HIGH로 합니다,
//    delayMicroseconds(b);               //d밀리초만큼 대기한뒤
//    digitalWrite(m2stp, LOW);  // stp를 LOW로 합니다.
//    delayMicroseconds(b);               //d밀리초만큼 대기한뒤
//    Serial.println(currentMillis);
//  }

  currentMillis = 0;
}
