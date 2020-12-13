# imboccaTauro
Approach to fix a MixFeeder

## Fütterungssteuerung ##
Toursteuerung eines Fütterungsroboters

## Links ##
- https://raspberryautomation.com/raspberry-pi-relay-module-via-gpio/
- https://dev.to/tardisgallifrey/raspberry-pi-gpio-4-ways-45do
- https://projects-raspberry.com/introduction-to-accessing-the-raspberry-pis-gpio-in-c-sysfs/
- https://www.youtube.com/watch?v=Uq7fkcl6PWs
- https://mklimenko.github.io/english/2016/07/08/managing-threads-qt-en/

## Aufbau ##

### Eingänge ###
- 2 Not-Aus
- 1 Waage
- 1 Sensor für Klappe
- Stopp
- 2 Markörsensoren

### Ausgänge ###
- 4 - 8 Relais für Futtertypen
- 1 Relais für Mischmotor
- 1 Relais für Klappe
- 2 Relais für Antriebsmotor
- 1 Näherungsschalter Antriebswelle

## Näherungsschalter ##
- Je 3 Kontakte

## Erweiterungen ##
- Temperaturabhängige Gewichtssteuerung (hohe Temperatur -> weniger Futter)
- Antrieb ohne gleichzeitige Positionsänderung (ohne Marköre) -> Störung (Indoor-Positionstechnologien?)
- Beidseitiges Auswerfen bzw. Steuerung der Auswerfrichtung


## Produktnummer ##
- 
- 

## Set up Raspberry ##
- https://www.youtube.com/watch?v=TmtN3Rmx9Rk
