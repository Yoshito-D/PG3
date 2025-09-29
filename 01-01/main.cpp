#include <iostream>
#include <Windows.h>
#include <list>
#include <cstdint>

void PrintStationsWithInsert(std::list<const char*>& stations, int32_t year, const char* target = nullptr, const char* insertAfter = nullptr);

int main() {
	std::list<const char*> yamanoteStations{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori", "Tabata",
		"Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki",
		"Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	PrintStationsWithInsert(yamanoteStations, 1970, "Tabata", "Nishi-Nippori");
	PrintStationsWithInsert(yamanoteStations, 2019, "Tamachi", "Takanawa Gateway");
	PrintStationsWithInsert(yamanoteStations, 2022);

	return 0;
}

void PrintStationsWithInsert(std::list<const char*>& stations, int32_t year, const char* target, const char* insertAfter) {
	std::cout << "\n" << year << std::endl;

	for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
		std::cout << "- " << *itr << std::endl;

		if (target && insertAfter && *itr == target) {
			itr = stations.insert(itr, insertAfter);
			++itr;
		}
	}
}