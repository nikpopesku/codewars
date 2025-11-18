#include <unordered_set>
#include <vector>
#include <algorithm>

#include "../cw_compat.hpp"

using namespace std;

struct Image {
    unsigned *pixels;
    unsigned width, height;

    Image(const std::initializer_list<unsigned> pixel_data, const unsigned w, const unsigned h) : width(w), height(h) {
        pixels = new unsigned[pixel_data.size()];
        std::copy(pixel_data.begin(), pixel_data.end(), pixels);
    }

    ~Image() {
        delete[] pixels;
    }

    unordered_set<unsigned> filter(unordered_set<unsigned> s) const {
        vector<unsigned> for_removal;
        const unsigned mx = width * height;
        const vector directions = {-static_cast<int>(width), static_cast<int>(width), -1, 1};
        for (auto &elem: s) {
            for (const auto d: directions) {
                const int val = static_cast<int>(elem) + d;
                if (val < 0 || val >= static_cast<int>(mx)) {
                    for_removal.push_back(elem);
                }
                if (val >= 0 && val < static_cast<int>(mx) && s.count(static_cast<unsigned>(val)) == 0) {
                    for_removal.push_back(elem);
                }
            }
        }

        for (auto &elem: for_removal) {
            s.erase(elem);
        }

        return s; // Return the filtered set
    }

    [[nodiscard]] vector<unsigned> central_pixels(const unsigned colour) const {
        unordered_set<unsigned> s;

        for (unsigned row = 0; row < height; ++row) {
            for (unsigned col = 0; col < width; ++col) {
                if (pixels[row * width + col] == colour) {
                    s.insert(row * width + col);
                }
            }
        }

        while (true) {
            if (auto new_s = filter(s); !new_s.empty()) {
                s = new_s;
            } else {
                break;
            }
        }

        vector<unsigned> response{s.begin(), s.end()};

        return response;
    }
};


/* ---------------------------------------------------------------------------------- */
/*                               TESTS                                                */
/* ---------------------------------------------------------------------------------- */

Describe(Centre_of_attention) {
    It(Example_In_The_Picture) {
        const Image image({
              1, 1, 4, 4, 4, 4, 2, 2, 2, 2,
              1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
              1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
              1, 1, 1, 1, 1, 3, 2, 2, 2, 2,
              1, 1, 1, 1, 1, 3, 3, 3, 2, 2,
              1, 1, 1, 1, 1, 1, 3, 3, 3, 3
          }, 10, 6);

        // Only one red pixel has the maximum depth of 3:
        vector<unsigned> red_ctr = {32};
        Assert::That(image.central_pixels(1), Fulfills(Unordered_Match(red_ctr)));

        // Multiple blue pixels have the maximum depth of 2:
        vector<unsigned> blue_ctr = {16, 17, 18, 26, 27, 28, 38};
        Assert::That(image.central_pixels(2), Fulfills(Unordered_Match(blue_ctr)));

        // All the green pixels have depth 1, so they are all "central":
        vector<unsigned> green_ctr = {35, 45, 46, 47, 56, 57, 58, 59};
        Assert::That(image.central_pixels(3), Fulfills(Unordered_Match(green_ctr)));

        // Similarly, all the purple pixels have depth 1:
        vector<unsigned> purple_ctr = {2, 3, 4, 5};
        Assert::That(image.central_pixels(4), Fulfills(Unordered_Match(purple_ctr)));

        // There are no pixels with colour 5:
        vector<unsigned> non_existent_ctr = {};
        Assert::That(image.central_pixels(5), Fulfills(Unordered_Match(non_existent_ctr)));

        // Changing one pixel can make a big difference to the result:
        image.pixels[32] = 3;
        vector<unsigned> new_ctr = {11, 21, 41, 43};
        Assert::That(image.central_pixels(1), Fulfills(Unordered_Match(new_ctr)));
    }
};
