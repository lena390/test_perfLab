//
// Created by Elena Lungu on 5/3/21.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

float get_perc(std::vector<float> & numbers, int perc) {
    int element_number = ceil((perc * numbers.size() / 100));
    return numbers.at(element_number - 1);
}

float get_average_value(std::vector<float> & numbers) {
    float total = 0;
    int i = 0;
    while (i != numbers.size()) {
        total += numbers.at(i);
        i++;
    }
    return total / numbers.size();
}

int main(int ac, char *av[]) {
    if (ac != 2)
        return 1;

    FILE *istream;
    istream = fopen(av[1], "r");
    if (istream == NULL)
        return 2;

    std::vector<float> numbers;
    int i;
    while (fscanf(istream, "%d\n", &i) == 1)
        numbers.push_back(i);
    fclose(istream);
    if (numbers.empty())
        return 3;

    std::sort(numbers.begin(), numbers.end());

    printf("%.2f\n", get_perc(numbers, 90));
    printf("%.2f\n", get_perc(numbers, 50));
    printf("%.2f\n", numbers.back());
    printf("%.2f\n", numbers.front());
    printf("%.2f\n", get_average_value(numbers));
}