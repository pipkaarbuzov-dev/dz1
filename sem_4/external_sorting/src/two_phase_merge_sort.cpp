#ifndef TWO_PHASE_MERGE_SORT_CPP
#define TWO_PHASE_MERGE_SORT_CPP

#include <fstream>
#include <algorithm>
#include <filesystem>

template<typename T>
std::vector<T> two_phase_merge_sort(const std::vector<T>& input, size_t run_size) {
    if (input.empty()) return {};
    std::vector<std::string> runs;
    for (size_t i = 0; i < input.size(); i += run_size) {
        size_t sz = std::min(run_size, input.size() - i);
        std::vector<T> chunk(input.begin() + i, input.begin() + i + sz);
        std::sort(chunk.begin(), chunk.end());
        std::string fn = "tp_" + std::to_string(i) + ".bin";
        std::ofstream ofs(fn, std::ios::binary);
        size_t s = chunk.size();
        ofs.write((char*)&s, sizeof(s));
        ofs.write((char*)chunk.data(), s * sizeof(T));
        runs.push_back(fn);
    }
    std::vector<T> res;
    for (auto& f : runs) {
        std::ifstream ifs(f, std::ios::binary);
        size_t s; ifs.read((char*)&s, sizeof(s));
        std::vector<T> tmp(s);
        ifs.read((char*)tmp.data(), s * sizeof(T));
        std::vector<T> merged;
        std::merge(res.begin(), res.end(), tmp.begin(), tmp.end(), std::back_inserter(merged));
        res = std::move(merged);
        std::filesystem::remove(f);
    }
    return res;
}
#endif
