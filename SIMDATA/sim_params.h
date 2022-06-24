#ifndef SIM_PARAMS_H
#define SIM_PARAMS_H

class ParamSim
{
    public:
        ParamSim();
        ~ParamSim(){};

        long double getLat(){return latitude;};
        long double getLong(){return longitude;};
        float getAltAsl() {return alt_asl;}
        float getHdg(){return hdg;};

        float getSpeedGround(){return speed_ground;};

        float getSats(){return sats;};

        void setLat(long double latitude_){latitude = latitude_;};
        void setLong(long double longitude_){longitude = longitude_;};
        void setAltAsl(float alt_){alt_asl = alt_;};
        void setHdg(float hdg_){hdg = hdg_;};

        void setSpeedGround(float speed_){speed_ground = speed_;};

        void setSats(int sats_){sats = sats_;};

        void Update();


    private:
        //Aircraft position
        long double latitude;
        long double longitude;
        float alt_asl;
        float hdg;

        //Aircraft speed
        float speed_ground;


        //Available satellites
        int sats;

        int count;


};



#endif