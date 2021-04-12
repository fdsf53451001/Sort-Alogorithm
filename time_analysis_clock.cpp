#include <iostream>
#include <ctime>
using namespace std;
/*
int main(){
    clock_t s_time = clock();
    for (int i = 0; i < 100;i++){
        cout << i << endl;
    }
    clock_t e_time = clock();
    double time = (double)(e_time - s_time) / CLOCKS_PER_SEC;
    cout << "CLOCKS_PER_SEC : " << CLOCKS_PER_SEC << endl;
    cout << time << endl;
}
*/
class time_analysis_clock{
    private:
        clock_t s_time = 0;
        clock_t e_time = 0;
    public:
        void start(){
            s_time = clock();
        }
        double end(){
            e_time = clock();
            if(s_time != 0){
                double time = (double)(e_time - s_time) / CLOCKS_PER_SEC;
                return time;
            }
            return -1;
        }
};