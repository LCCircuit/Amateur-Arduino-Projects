#include <string.h>

const char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
const char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};


const char** morse(const char* clause) {
    //const int len = strlen(clause);
    static const char* str[100];
    for(int i = 0; clause[i] != '\0'; i++) {
        if(clause[i] >= '0' && clause[i] <= '9') {
            str[i] = numbers[(clause[i] - '0')];
        }
        else if(clause[i] >= 'a' && clause[i] <= 'z') {
            str[i] = letters[(clause[i] - 'a')];
        }
        else if(clause[i] >= 'A' && clause[i] <= 'Z') {
            str[i] = letters[(clause[i] - 'A')];
        }
        else {
            str[i] = " ";
        }
    }
    return str;
}

void decoder(const char** morseresult, int length, int unit, int pincode) {
    for(int i = 0; i < length; i++){
        if(morseresult[i] == ' ') {
            delay(unit*7);
            continue;
        }
        for(int j = 0; j < strlen(morseresult[i]); j++) {
            if(morseresult[i][j] == '.') {
                digitalWrite(pincode, HIGH);
                delay(unit);
                digitalWrite(pincode, LOW);
                delay(unit);
            }
            else if(morseresult[i][j] == '-') {
                digitalWrite(pincode, HIGH);
                delay(unit*3);
                digitalWrite(pincode, LOW);
                delay(unit);
            }
        }
        delay(unit*3);
    }
}

void setup() {
  pinMode(13, OUTPUT);
  decoder(morse("Hello World"), 11, 1000, 13);
}

void loop() {
}
