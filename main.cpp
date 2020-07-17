#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>

int main(){
	char English[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y','w', 'z', ' '};
	std::string Morse[] {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};

	int choice;
	int eN;

	std::cout << "0: Morse->English\n1: English->Morse" << std::endl;
	std::cout << "I: ";
	std::cin >> choice;
	std::string Buffer;
	std::getline(std::cin.ignore(), Buffer);
	switch(choice){
		case 0: {
				eN = sizeof(Morse)/sizeof(Morse[0]);
				std::stringstream sao(Buffer);
				std::string tmp;
				std::vector<std::string>buffer2;
				int i = 0;
				while(std::getline(sao, tmp, ' ')){
					buffer2.push_back(tmp);
					std::cout << tmp << std::endl;
				}
				for(int idx = 0; idx < buffer2.size(); idx++){
					auto irt = std::find(Morse, Morse + eN, buffer2[idx]);
					std::cout << English[std::distance(Morse, irt)];
				}
				break;
			}
		case 1: {
				eN = sizeof(English)/sizeof(English[0]);
				for(int idx = 0; idx < (unsigned)std::strlen(Buffer.c_str()); idx++){
					auto irt = std::find(English, English + eN, Buffer[idx]);
					std::cout << Morse[std::distance(English, irt)] << " ";
				}
				break;
			}
	}
	std::cout << std::endl;
	return 0;
}
