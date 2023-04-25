// lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm> 

struct compare {
    bool operator()(std::pair<std::string, int>& x, std::pair<std::string, int>& y) const {
        if (x.second != y.second)
            return x.second < y.second;
        else
            return (x.first.compare(y.first) > 0);
    }
};
void lowercase(std::string& str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}

void print_queue(std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> queue) {
    while (!queue.empty()) {
        std::cout << queue.top().first << " => " << queue.top().second << "\n";
        queue.pop();
    }
}
//void phrase_to_map(std::string s, std::map<std::string, int>& freq_map) {
//    std::string str;
//    std::string delimitator = " ,.!?";
//    for (int i = 0; i < s.length(); i++) {
//        if (delimitator.find(s[i]) != std::string::npos) {
//            if (!str.empty()) {
//                lowercase(str);
//                freq_map[str]++;
//            }
//            str.clear();
//            continue;
//        }
//        str += s[i];
//    } 
//}

void phrase_to_map(std::string s, std::map<std::string, int>& freq_map) {
    std::string delimitator = " ,.?!);";
    std::size_t found, min_found;
    while (!s.empty()) {
        found = s.find_first_of(delimitator);
        if (found != std::string::npos) {
            min_found = found;
            std::size_t temp_found;
            for (std::string::iterator it = delimitator.begin(); it != delimitator.end(); ++it) {
                temp_found = s.find_first_of(*it);
                if (temp_found != std::string::npos && temp_found < min_found) {
                    min_found = temp_found;
                }
            }
            std::string word = s.substr(0, min_found);
            lowercase(word);
            freq_map[word]++;
            s = s.substr(min_found);
        }
        else {
            std::string word = s;
            lowercase(word);
            freq_map[word]++;
            s.clear();
        }
        s.erase(0, s.find_first_not_of(delimitator));
    }
}

void map_to_queue(std::map<std::string, int> map, std::priority_queue < std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare>& my_queue) {
    std::map<std::string, int>::iterator it;
    for (it = map.begin(); it != map.end(); it++) {
        std::pair<std::string, int> pair;
        pair.first = it->first; 
        pair.second = it->second;
        my_queue.push(pair);
    }

}

int main() {
    std::string s;
    std::map<std::string, int> freq_map;
    std::fstream fisier;
    fisier.open("test.txt");
    std::getline(fisier, s);
    phrase_to_map(s, freq_map);
    std::priority_queue < std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, compare> queue;
    map_to_queue(freq_map, queue);
    print_queue(queue);
    return 0;
}