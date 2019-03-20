#ifndef AD_KEC_WI201819_FELD_H
#define AD_KEC_WI201819_FELD_H

class Feld {
public:
    void Init(int length);
    
    void FillRandom();
    
    int Min();

    int Max();

    int Avg();
    
    void Print();

private:
    int length;
    int* array;
};


#endif //AD_KEC_WI201819_FELD_H