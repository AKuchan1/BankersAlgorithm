#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::ifstream inFile;
    std::string line;
    std::vector<std::string> doc;
    inFile.open("processes.txt");
    if (inFile.is_open()) {
        while (getline(inFile, line, ' ')) {
            doc.push_back(line);
        }
    }
    inFile.close();
    inFile.open("available.txt");
    if (inFile.is_open()) {
        while (getline(inFile, line, ' ')) {
            doc.push_back(line);
        }
    }
    inFile.close();
    int n, m;
    n = 5; // Number of process
    m = 3; // Number of resources
    int alloc[5][3] = {}; // P4
    int max[5][3] = {}; // P4
    int avail[3] = {}; // Available resources
    int count = 0;
    int index = 0;
    bool flag = false;
    for (int i = 0; i < doc.size(); i++) {
        if (count < 3 && index < 5) {
            if (!flag) {
                alloc[index][count] = std::stoi(doc[i]);
                count++;
            }
            else {
                max[index][count] = std::stoi(doc[i]);
                count++;
            }
        }
        else if (index < 5) {
            if (!flag){
                i--;
                count = 0;
                flag = true;
            }
            else {
                i--;
                count = 0;
                index++;
                flag = false;
            }
        }
        else {
            avail[count] = std::stoi(doc[i]);
            count++;
        }
    }
    int f[n], ans[n], ind = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            if (f[j] == 0) {
                int flag = 0;
                for (int k = 0; k < m; k++) {
                    if (need[j][k] > avail[k]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = j;
                    for (int y = 0; y < m; y++) {
                        avail[y] += alloc[j][y];
                    }
                    f[j] = 1;
                }
            }
        }
    }
    std::cout << "Following is the safe sequence" << std::endl;
    for (int i = 0; i < n - 1; i++) {
        std::cout << " P" << ans[i] << " ->";
    }
    std::cout << " P" << ans[n - 1] << std::endl;
    return 0;
}