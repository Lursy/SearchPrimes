#include <iostream>
#include <string>

int main() {
    int length = 1, real = 0, maior = 0;
    int primos[200] = {2};
    std::string final = "";

    for (int i = 3; i < 1000000; i += 2) {
        int primo = 1;
        for (int c = 0; c < length * 0.2; c++) {
            if (i % primos[c] == 0) {
                if (primos[c] > maior) {
                    maior = primos[c];
                }
                primo = 0;
                break;
            }
        }

        if (primo == 1) {
            if (i < 998) {
                primos[length] = i;
                length++;
            }
            final += std::to_string(i) + " ";
            real++;
        }
    }
    std::cout << final << std::endl;
    std::cout << "Lista: " << real << ", " << primos[length - 1] << ", " << maior << ", " << length << std::endl;
    return 0;
}
