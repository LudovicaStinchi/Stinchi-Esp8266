#include <ESP8266WiFi.h>
  #define LED_BUILTIN 2
  
  const char* ssid = "Ludo";
  const char* password = "stinchi2003";
  bool visual=false;
  const String Lista[] = { "Carbonara","Cacio e Pepe","Amatriciana","Tiramisù","Torta Di Mele"};
  
  // Definizione di un socket server alla porta 10107
  WiFiServer server(10107);
  
  
  void setup() {
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    
    WiFi.begin(ssid, password);  
  
    Serial.println("Connessione...");
    while(WiFi.status() != WL_CONNECTED){ delay(500); }
    Serial.print("Connesso, IP: ");    Serial.println( WiFi.localIP() );
  
    server.begin();
    Serial.println("Server aperto porta utilizzata 10107");
  }
  
  
  void loop() {
     WiFiClient cliente = server.available();
     if(!cliente){  return;  }
     cliente.println("Connesso al Server Ricettario");
     cliente.println("Scegli la ricetta scrivendo:");
     cliente.println("0 == Carbonara");
     cliente.println("1 == Cacio e Pepe");
     cliente.println("2 == Amatriciana");
     cliente.println("3 == Tiramisù");
     cliente.println("4 == Torta di Mele");
     cliente.println("");
     cliente.println("Inserisci il numero della ricetta e delle persone separate da un -");
     
     Serial.println("New Client Connesso");
    while(true){
        while(!cliente.available()){  delay(100);  }            
        String message = cliente.readStringUntil('\r');
        message.replace("\n", "");
        message.replace("\r", "");

        String ricetta="";
        String persone="";
        for(int i=0;i<message.length();i++)
        {
          char num=message[i];
          if(num !='-' && message.indexOf(num)<message.indexOf("-"))
          {
            ricetta+=num;
          }else if(num !='-' && message.indexOf(num)>message.indexOf("-"))
          {
            persone+=num;  
          }
        }
        

        if(message.length() > 0){
         
            Serial.print("N Ricetta: ");  Serial.println(ricetta);                      
            Serial.print("N Persone: ");  Serial.println(persone);   
            delay(1);
      
            String stampa="";     
            /*carbonara*/  
           int ottanta=80; 
           int trentasette=37 ; 
           int unocinque=1;
           int dodici=12;
            if(ricetta=="0"){
            stampa+=Lista[message.toInt()];
            cliente.println(stampa + " per " + ricetta +" persone");
            cliente.print("Spaghetti "); cliente.print (ottanta*ricetta.toInt());     cliente.println("g");
            cliente.print("Guanciale "); cliente.print (trentasette*ricetta.toInt()); cliente.println("g");
            cliente.print("Tuorli " );   cliente.print (unocinque*ricetta.toInt());   cliente.println("g");
            cliente.print("Pecorino ");  cliente.print (dodici*ricetta.toInt());      cliente.println("g");
            cliente.println("Pepe a piacere");
            cliente.println("Per Vedere i Passaggi della Ricetta Copia Il Link");
            cliente.println("https://ricette.giallozafferano.it/Spaghetti-alla-Carbonara.html");
         
            }
            
            /*Cacio e Pepe*/ 
            int cinquanta=50;
            if(ricetta=="1"){
            stampa+=Lista[message.toInt()];
            cliente.println(stampa + " per " + persone +" persone");
            cliente.print("Spaghetti "); cliente.print (ottanta*persone.toInt());      cliente.println("g");
            cliente.print("Pecorino ");  cliente.print (cinquanta*persone.toInt());    cliente.println("g");
            cliente.println("Pepe Nero a piacere");
            cliente.println("Sale Fino a piacere");
            cliente.println("Per Vedere i Passaggi della Ricetta Copia Il Link");
            cliente.println("https://ricette.giallozafferano.it/Spaghetti-Cacio-e-Pepe.html");   
            }
            
            /*Amatriciana*/ 
            if(ricetta=="2"){
              int cento=100;
            stampa+=Lista[message.toInt()];
            cliente.println(stampa + " per " + persone +" persone");
            cliente.print("Spaghetti "); cliente.print (ottanta*persone.toInt());     cliente.println("g");
            cliente.print("Guanciale "); cliente.print (trentasette*persone.toInt()); cliente.println("g");
            cliente.print("Pomodoro " );   cliente.print (cento*persone.toInt());     cliente.println("g");
            cliente.print("Pecorino ");  cliente.print (dodici*persone.toInt());      cliente.println("g");
            cliente.print("Vino Bianco ");  cliente.print (dodici*persone.toInt());      cliente.println("g");
            cliente.println("Pepe Nero a piacere");
            cliente.println("Sale Fino a piacere");
            cliente.println("Un peperoncino");
            cliente.println("Per Vedere i Passaggi della Ricetta Copia Il Link");
            cliente.println("https://ricette.giallozafferano.it/Spaghetti-all-Amatriciana.html");         
            }

            /*Tiramisu*/ 
            int novantatre=93;
            int trentadue=32 ; 
            if(ricetta=="3"){
            stampa+=Lista[message.toInt()];
            cliente.println(stampa + " per " + persone +" persone");
            cliente.print("Mascarpone ");  cliente.print (novantatre*persone.toInt());     cliente.println("g");
            cliente.print("Caffe ");       cliente.print (trentasette*persone.toInt()); cliente.println("g");
            cliente.print("Savoiardi " );   cliente.print (trentadue*persone.toInt());     cliente.println("g");
            cliente.print("Uova " );   cliente.print (trentadue*persone.toInt());     cliente.println("g");
            cliente.print("Zucchero ");    cliente.print (dodici*persone.toInt());      cliente.println("g");
            cliente.println("Cacao a piacere");
            cliente.println("Per Vedere i Passaggi della Ricetta Copia Il Link");
            cliente.println("https://ricette.giallozafferano.it/Tiramisu.html");         
            }

            /*Torta Di Mele*/ 
            int centosedici=116;
            int venticinque=25;
            int due=2;
            int uno=1;
            if(ricetta=="4"){
            stampa+=Lista[message.toInt()];
            cliente.println(stampa + " per " + persone +" persone");
            cliente.print("Mele "); cliente.print (centosedici*persone.toInt());     cliente.println("g");
            cliente.print("Zucchero "); cliente.print (venticinque*persone.toInt()); cliente.println("g");
            cliente.print("Farina " );   cliente.print (trentadue*persone.toInt());     cliente.println("g");
            cliente.print("Burro ");  cliente.print (dodici*persone.toInt());      cliente.println("g");
            cliente.print("Latte ");  cliente.print (dodici*persone.toInt());      cliente.println("g");
            cliente.print("Lievito ");  cliente.print (due*persone.toInt());      cliente.println("g");
            cliente.print("Uovo ");  cliente.print (uno*persone.toInt());      cliente.println("g");            
            cliente.println("Sale Fino un pizzico");
            cliente.println("Per Vedere i Passaggi della Ricetta Copia Il Link");
            cliente.println("https://ricette.giallozafferano.it/Torta-rustica-di-mele.html");                
            }

       if(message.indexOf("CLOSE") > -1){
               Serial.println("Client disconnesso...");
               cliente.stop();
            }






            
        }
    }
     }  
