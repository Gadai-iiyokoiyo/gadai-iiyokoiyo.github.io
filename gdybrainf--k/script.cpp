#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    std::vector<char> run_list;
    int power = 0;
    int int_cp = 0;
    std::vector<float> fl_p;
    std::vector<char> str_p;
    for (int i = 0; i < 200; i++)
    {
        fl_p.push_back(0);
    }
    
    std::ifstream file(argv[1]);
    int count = 0;
    if (file.is_open()) {
        char getstr;
        while (file.get(getstr)) {
            run_list.push_back(getstr);
            count++;
        }
        file.close();
        for (int i = 0; i < count; i++) {
            if(run_list[i]=='g' && run_list[i+1]=='b' && run_list[i+2] =='f' && run_list[i+3] =='1' && run_list[i+4] =='\n' && power == 0){
                power = 1;
            }
            if(power == 1){
                if (run_list[i]=='a'){
                    fl_p[int_cp]++;
                }
                else if (run_list[i]=='b'){
                    fl_p[int_cp]--;
                }
                else if (run_list[i]=='A'){
                    int_cp++;
                }
                else if (run_list[i]=='B'){
                    int_cp--;
                }
                else if (run_list[i]=='c'){
                    str_p.push_back(run_list[i+1]);
                    i++;
                }   
                else if (run_list[i]=='d'){
                    for (char c : str_p) {
                        std::cout << c;
                    }
                }
                else if (run_list[i]=='e'){
                    std::cout << fl_p[int_cp];
                }
                else if (run_list[i] == 'C'){
                    str_p.clear();
                }
                else if (run_list[i] == 'f'){
                    fl_p[int_cp+1]=fl_p[int_cp-1]+fl_p[int_cp];
                }
                else if (run_list[i] == 'F'){
                    fl_p[int_cp+1]=fl_p[int_cp-1]*fl_p[int_cp];
                }
                else if (run_list[i] == 'g'){
                    fl_p[int_cp+1]=fl_p[int_cp-1]-fl_p[int_cp];
                }
                else if (run_list[i] == 'G'){
                    if(fl_p[int_cp] == 0){
                        printf("[ERR]\t It is impossible to divide by 0.");
                        break;
                    }
                    fl_p[int_cp+1]=fl_p[int_cp-1]/fl_p[int_cp];
                }
                
                
                
            }
        }
    } else {
        std::cout << "[ERR]\tFileOpen" << std::endl;
    }
    return 0;
}
