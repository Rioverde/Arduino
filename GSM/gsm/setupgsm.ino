#include <GSM.h>
#include <Servo.h>   

// PIN Number for the SIM
#define PINNUMBER ""

// initialize the library instances
GSM gsmAccess;
GSM_SMS sms;
Servo ServMotor;

// Array to hold the number a SMS is retreived from
char senderNumber[20];
int angle = 0;    

void setup() {

  ServMotor.attach(10);   
  
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("SMS Messages Receiver");

  // connection state
  bool notConnected = true;

  // Start GSM connection
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
  Serial.println("Waiting for messages");
  Serial.println("-----Send Message------");
}

void loop() {
  char c;
  String MessageIn = "";

  // If there are any SMSs available()
  if (sms.available()) {
    Serial.println("Message received from:");

    // Get remote number
    sms.remoteNumber(senderNumber, 20);
    Serial.println(senderNumber);
    Serial.println("------------------");

    // An example of message disposal
    // Any messages starting with # should be discarded
    if (sms.peek() == '#') {
      Serial.println("Discarded SMS");
      sms.flush();
      delay(50);
    }

    // Read message bytes and print them
    while (c = sms.read()) {
      MessageIn += c;
    }

    Serial.println("Received Message: ");
    Serial.println("------------------");
    Serial.println(MessageIn);

    Serial.println("------------------");
    Serial.println("\nEND OF MESSAGE");


    if(MessageIn == "LedOn")
    {
        digitalWrite(9,HIGH);
        delay(50);
    }
      else if(MessageIn == "LedOff"){
        digitalWrite(9,LOW);
        delay(50);

      }
      else if(MessageIn == "ServoOn"){
          for(angle = 0; angle < 90; angle += 1)    
            {                                  
              ServMotor.write(angle);                 
              delay(15);                       
            } 

      }
      
      else if(MessageIn == "ServoOff"){
          for(angle = 90; angle>=1; angle-=5)  
            {                                  
              ServMotor.write(angle);                 
              delay(15);                       
            } 

      }
      
      

    sms.flush();
    delay(100);
    Serial.println("------------------");
    Serial.println("MESSAGE DELETED FROM MEMORY");
    
    Serial.println("------------------");
    Serial.println("TASKS DONE");
  }

  delay(1000);

}
