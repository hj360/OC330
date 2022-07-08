#include "adiru.h"

Adiru::Adiru(SensorManager* Sensors_, int id_)
{
    id = id_;
    Sensors = Sensors_;

    if(id == 2)
    {
        ActiveMMR = Sensors->MMR2;
        AltMMR = Sensors->MMR1;
    } else {
        ActiveMMR = Sensors->MMR1;
        AltMMR = Sensors->MMR2;
    }

}

void Adiru::Update()
{
    if(ActiveMMR->getGPSStatus())
    {
        GPS_lat = ActiveMMR->getGPSLat();
        GPS_long = ActiveMMR->getGPSLong();
        GPS_alt = ActiveMMR->getGPSAlt();
        GPS_hdg = ActiveMMR->getGPSHdg();
        GPS_gs = ActiveMMR->getGPSGs();

    } else if(AltMMR->getGPSStatus())
    {
        GPS_lat = AltMMR->getGPSLat();
        GPS_long = AltMMR->getGPSLong();
        GPS_alt = AltMMR->getGPSAlt();
        GPS_hdg = AltMMR->getGPSHdg();
        GPS_gs = AltMMR->getGPSGs();
    } else {
        
    }
}