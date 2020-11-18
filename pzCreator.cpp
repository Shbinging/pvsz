#include"plant.h"
#include"zombie.h"
#include"pzCreator.h"
#include"map.h"
#include"diag.h"
#include"shop.h"
object* pzCreator::createObject(int id, MAP& m, shop& n, location x,int t){
            object* p = NULL;
            switch(id){
                case 10: p = new plantSun(x, t, &m, &n); break;
                case 11: p = new plantWandou(x, t, &m, &n); break;
                case 12: p = new plantHanbing(x, t, &m, &n); break;
                case 13: p = new plantShuangfa(x, t, &m, &n); break;
                case 14: p = new plantNut(x, t, &m, &n); break;
                case 15: p = new plantNutHigh(x, t, &m, &n); break;
                case 16: p = new plantWogua(x, t, &m, &n); break;
                case 17: p = new plantCherrish(x, t, &m, &n); break;
                case 18: p = new plantSuan(x, t, &m, &n); break;
                case 20: p = new zombieBasic(x, t, &m, &n); break;
                case 30: p = new plantNan(x, t, &m, &n); break;
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
                case 10: p = new plantSun(x, t, NULL, NULL); break;
                case 11: p = new plantWandou(x, t, NULL, NULL); break;
                case 12: p = new plantHanbing(x, t, NULL, NULL); break;
                case 13: p = new plantShuangfa(x, t, NULL, NULL); break;
                case 14: p = new plantNut(x, t, NULL, NULL); break;
                case 15: p = new plantNutHigh(x, t, NULL, NULL); break;
                case 16: p = new plantWogua(x, t, NULL, NULL); break;
                case 17: p = new plantCherrish(x, t, NULL, NULL); break;
                case 18: p = new plantSuan(x, t, NULL, NULL); break;
                case 30: p = new plantNan(x, t, NULL, NULL); break;
                default:
                    p = NULL;
            }
            if (p) list.push_back(p);
    }
    return list;
}