#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::swap
#include <cctype>    // std::tolower

// Függvény, amely eltávolítja a stringből a nem-betű karaktereket, és kisbetűssé alakítja
std::string normalizeString(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            result += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return result;
}

// Szimmetria ellenőrző függvény (palindróm ellenőrzés)
bool isPalindrome(const std::string& originalInput) {
    std::string input = normalizeString(originalInput);
    std::size_t left = 0;
    std::size_t right = input.length();

    if (right == 0) {
        std::cout << "A string üres, így szimmetrikusnak tekinthető." << std::endl;
        return true;
    }

    right--; // A jobb oldali mutatót a végére tesszük

    while (left < right) {
        if (input[left] != input[right]) {
            std::cout << "Nem egyezik: '" << input[left] << "' != '" << input[right] << "'\n";
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Tömb rendezése buborékrendezéssel, túlmagyarázva
void sortArray(std::vector<int>& arr) {
    std::cout << "A rendezés megkezdése a következő tömbön: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bool swapped = true;
    int iteration = 0;

    // Klasszikus buborékrendezés megvalósítása
    while (swapped) {
        swapped = false;
        iteration++;
        std::cout << "Iteráció #" << iteration << std::endl;

        for (std::size_t i = 0; i < arr.size() - 1; ++i) {
            std::cout << "Összehasonlítás: arr[" << i << "] = " << arr[i]
                      << " és arr[" << i + 1 << "] = " << arr[i + 1] << std::endl;

            if (arr[i] > arr[i + 1]) {
                std::cout << "-> Csere szükséges!" << std::endl;
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            } else {
                std::cout << "-> Nincs csere szükség." << std::endl;
            }
        }

        std::cout << "Aktuális állapot az iteráció végén: ";
        for (const int& num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        if (!swapped) {
            std::cout << "A tömb már rendezett." << std::endl;
        }
    }
}

int main() {
    // Palindróm teszt
    std::string testString;
    std::cout << "Adj meg egy szót vagy mondatot a palindróm ellenőrzéshez: ";
    std::getline(std::cin, testString);

    if (isPalindrome(testString)) {
        std::cout << "A megadott szöveg szimmetrikus (palindróm)." << std::endl;
    } else {
        std::cout << "A megadott szöveg nem szimmetrikus." << std::endl;
    }

    // Rendezés teszt
    std::vector<int> numbers;
    int numberOfElements;
    std::cout << "\nHány számot szeretnél rendezni? ";
    std::cin >> numberOfElements;

    std::cout << "Kérlek, add meg a számokat:" << std::endl;
    for (int i = 0; i < numberOfElements; ++i) {
        int num;
        std::cout << i + 1 << ". szám: ";
        std::cin >> num;
        numbers.push_back(num);
    }

    sortArray(numbers);

    std::cout << "A rendezett tömb: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
