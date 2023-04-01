MyWifiBoard.
dieses Projekt soll mindestens 4 chips miteinander verbinden.
den Leonardo als eigenständigen controler um über tastatureingaben automatisiert dinge z.B. die PC-Pflege übernehmen zu können oder um eine Hardweare Tastatur mittels NRF24 oder als wifi-tastatur über eine weboberfläche des ESP oder als bluetooth-tastatur mittels des ESP32 nutzen zu können.
Hierbei sollen die chips/microcontroler folgende aufgaben erhalten:

Leonardo beatle (ohne 3,3v ausgang)
    mit rx1/tx1 mit dem ESP32RX undTX verbunden
    mit i2c auf Adresse 0x02 mit dem ESP32 (0x03) sowie/oder dem esp8266(0x04) verbunden
    mit SPI am NRF24 angeschlossen als cs wird DI1 genutzt

alternativ der Digispark mit eingeschränkter funktionalität

esp8266-01s (1)
    Variante 1 als Hauptsteuerungs-modul (mit 1 MBIT spi-speicher)
        ist mittels rx/tx als einzelkomponente mit dem leonardo verbunden
        ist mittels i2c als einzelkomponente mit dem Leonardo verbunden

esp8266-01s (2)
    Variante 2 als webserver (für die Darstellung der Softwaretastatur)
        ist mittels rx/tx als einzelkomponente mit dem leonardo verbunden
        ist mittels i2c als einzelkomponente mit dem Leonardo verbunden

ESP32 
    mittels einer Seriellen Schnittstelle RX/TX am Leonardo-beatle oder dem Digispark angeschlossen. mit automatischer geschwindigkeitsanpassung auf der seriellen schnittstelle, abhängig davon welche Geräte am i2c-bus gefunden werden. (beim Leonardo 115200, beim Digispark 9600 BAUD)
    mittels SPI0 eine SD-Karte
    mittels SPI1 eine ansammlung von SPI-Chips, darunter "nrf24l01", der "cc1101" in 686 mhz und einer in 433 mhz Variante.
    an einer weiteren Seriellen Schnittstelle soll ein weiterer "esp8266 01s"
    diese chips sollen als slaves am esp32 hängen und von Ihm gesteuert werden.
    wenn eine Anfrage mittels i2c kommt, soll der esp ggf in einen Gateway modus übergehen und die Serielle Kommunikation die mittels RX/TX hineinkommt (erste serielle Schnittstelle ) an den selektierten esp8266, dem leonardo oder den spi-devices durchleiten.

somit sind folgende verschaltungen möglich:

    als mini:

    PC -> Digispark---->esp8266
            |----->(i2c)-->|

    oder value: 

                    |------->(i2c)------>|
    PC ->(USB)-> Leonardo ->(Serial)-> esp8266
          |-> (SPI) -> NRF24

    oder (monster):

                 |<--------------(virtual uart via esp32-gateway)---------->|
                 | |->(i2c)---------------------->|---------------------->| |
                 | |  |->(serial1)->esp8266(1)->| |                         |
    PC ->(USB)-> Leonardo ->(Serial)---------->esp32 -> (serial1) -> esp8266(2)
                    |->(SPI)->NRF24(0)         |  |->(spi0)->SD-Karte
                                               |-> (spi2)->|->nrf24(1) (2,4 Ghz)
                                                           |->cc1101   (915 Mhz)
                                                           |->cc1101   (868 Mhz)
                                                           |->cc1101   (433 mhz)



in einer 4. Variante kann das Monsterboard mittels Flipper-Zero bedient werden.
Hierzu werden SPI,I2c und Serial genutzt.
Serial zur Kommunikation mit dem ESP32, i2c zur steuerung der Gateway-Modis und SPI zur Ansteuerung der SPI-Chips. in diesem FAlle fungiert der Flipper als MAster und der ESP32 schaltet mittels seiner Pins die slaves aktiv. die Steuerung erfolgt mittels i2c zwischen flipper und esp32.