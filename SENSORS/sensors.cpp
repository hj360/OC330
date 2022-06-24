#include "sensors.h"

SensorManager::SensorManager(ParamSim* SIM_)
{
    SIM = SIM_;
    //Create MMRs
    MMR1 = new MMR(SIM);
    MMR2 = new MMR(SIM);

    //Power on MMR's
    MMR1->setPwr(1);
    MMR2->setPwr(1);
}

void SensorManager::Update()
{
    //Update MMR's
    MMR1->Update();
    MMR2->Update();
}