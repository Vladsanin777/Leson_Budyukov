#include <iostream>

using namespace std;

const char* digit_in_text(char digit){
	switch (digit){
		case '0': return "ноль";
		case '1': return "один";
		case '2': return "два";
		case '3': return "три";
		case '4': return "четыре";
		case '5': return "пять";
		case '6': return "шесть";
		case '7': return "семь";
		case '8': return "восемь";
		case '9': return "девять";
		default: return "другое";
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	char digit;
	cin>>digit;
	cout<<digit_in_text(digit)<<endl;
}
