#include"plant.h"
#include"zombie.h"
#include"pzCreator.h"
#include"map.h"
#include"diag.h"
#include"shop.h"
#define makeo(id, obj) case id: p=new obj(x, t, &m, &n); break;
#define makep(id, obj) case id: p=new obj(x, t, NULL, NULL); break;
object* pzCreator::createObject(int id, MAP& m, shop& n, location x,int t){
            object* p = NULL;
            switch(id){
                //case 10: p = new plantSun(x, t, &m, &n); break;
                makeo(10, plantSun)
                makeo(11, plantWandou)
                makeo(12, plantHanbing)
                makeo(13, plantShuangfa)
                makeo(14, plantNut)
                makeo(15, plantNutHigh)
                makeo(16, plantWogua)
                makeo(17, plantCherrish)
                makeo(18, plantSuan)
                makeo(20, zombieBasic)
                makeo(21, zombieLu)
                makeo(22, zombieBao)
                makeo(23, zombieGan)
                makeo(30, plantNan)
            }
            return p;
        }

vector<plantNormal*> pzCreator::getPlantList(){
    vector<plantNormal*> list;
    plantNormal* p;
    location x(0,0);
    int t = -1;
    list.push_back(NULL);
    For(i, 10, mxPlId){
            switch(i){
                makep(10, plantSun)
                    makep(11, plantWandou)
                    makep(12, plantHanbing)
                    makep(13, plantShuangfa)
                    makep(14, plantNut)
                    makep(15, plantNutHigh)
                    makep(16, plantWogua)
                    makep(17, plantCherrish)
                    makep(18, plantSuan)
                    makep(30, plantNan)
                default:
                    p = NULL;
            }
            if (p) list.push_back(p);
    }
    return list;
}