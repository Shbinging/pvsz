#ifndef CONFIG_H
#define CONFIG_H

#define isPlant(x) ((x/10 == 1) || (x / 10 == 3))
#define isZombie(x) ((x/10 == 2))
#define isProtecter(x) ((x/10 == 3))
#define Forr(i, l, r) for(int i = l; i < r; i++)
#define For(i, l, r) for(int i = l; i <= r; i++)
#define Down(i, r, l) for(int i = r; i >= l; i--)
const int windowWidth = 900;
const int windowHeight = 600;
#endif // CONFIG_H
