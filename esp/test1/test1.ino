/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/



// Load Wi-Fi library
#include <ESP8266WiFi.h>

#define BUTTON_MOTION_SLEEP_TIMOUT 15000
#define DEPOUNCE_TIME 150



// Replace with your network credentials
const char* ssid     = "Saleh";
const char* password = "14421442s";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "on";
String output4State = "on";

// Assign output variables to GPIO pins
const int output5 = 5;
const int output4 = 4;
const int motion = 15;
const int button = 0;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

int last_motion=0, last_push=0, new_push=0;

ICACHE_RAM_ATTR void buttonInterruptHandler(){
  new_push=millis();
  if(new_push-last_push>DEPOUNCE_TIME){
    Serial.println("buttonInterruptHandler()");
    if(output5State == "off"||output4State == "off"){
      output5State = "on";
      output4State = "on";
      digitalWrite(output5, LOW);
      digitalWrite(output4, LOW);
    }else{
      output5State = "off";
      output4State = "off";
      digitalWrite(output5, HIGH);
      digitalWrite(output4, HIGH);
    }
    last_motion=millis();
  }
  last_push=new_push;
}

ICACHE_RAM_ATTR void motionSensorInterruptHandler(){
  if((millis()-last_push)>BUTTON_MOTION_SLEEP_TIMOUT){
    output5State = "on";
    output4State = "on";
    digitalWrite(output5, LOW);
    digitalWrite(output4, LOW);
  }
}

void setup() {
  // Initialize the output variables as outputs
  Serial.begin(115200);
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);

  // Setup button interrupt
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), buttonInterruptHandler, FALLING);

  // Setup motion interrupt
  pinMode(motion, INPUT);
  attachInterrupt(digitalPinToInterrupt(motion), motionSensorInterruptHandler, RISING);
  
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  //Serial.print("Connecting to ");
  //Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  // Print local IP address and start web server
  //Serial.println("");
  //Serial.println("WiFi connected.");
  //Serial.println("IP address: ");
  //Serial.println(WiFi.localIP());
  server.begin();


}
void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
   //Serial.println(digitalRead(motion ));
   //Serial.println(digitalRead(button));
   
   

  if (client) {                             // If a new client connects,
    //Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        //Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            bool changed=false;
            if (header.indexOf("GET /5&4/on") >= 0) {
              //Serial.println("GPIO 5&4 on");
              output4State = "on";
              output5State = "on";
              digitalWrite(output4, !HIGH);
              digitalWrite(output5, !HIGH);
              changed=true;
            }else if (header.indexOf("GET /5&4/off") >= 0) {
              //Serial.println("GPIO 5&4 off");
              output4State = "off";
              output5State = "off";
              digitalWrite(output4, !LOW);
              digitalWrite(output5, !LOW);
              last_motion=millis();
              changed=true;
            }else if (header.indexOf("GET /5/on") >= 0) {
              //Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, !HIGH);
              changed=true;
            } else if (header.indexOf("GET /5/off") >= 0) {
              //Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, !LOW);
              changed=true;
            } else if (header.indexOf("GET /4/on") >= 0) {
              //Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, !HIGH);
              changed=true;
            } else if (header.indexOf("GET /4/off") >= 0) {
              //Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, !LOW);
              changed=true;
            }
            if (changed)client.println("<meta http-equiv=\"refresh\" content=\"0; url='../'\" />");
            
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html lang=\"ar\">");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, charset=\"UTF-8\"\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: red; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println("table, th, td {border: 1px solid black;}");
            client.println(".button2 {background-color: green;}</style></head>");

            //table

            client.println("<table style=\"width:100%\">");

    
            
            
            //saleh's room

            client.println("<tr><th><h2>Saleh's room</h2>");
            
            
            // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>Toggol both lights</p>");
            if (output5State=="off"||output4State=="off") {
              client.println("<p><a href=\"/5&4/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/5&4/off\"><button class=\"button button2\">ON</button></a></p>");
            } 
            
            client.println("<p>Right light - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">ON</button></a></p>");
            } 
             
            // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>Left light - State " + output4State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">ON</button></a></p>");
            }
            client.println("</th></tr></table></body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
            
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    //Serial.println("Client disconnected.");
    //Serial.println("");

    
  }
}
