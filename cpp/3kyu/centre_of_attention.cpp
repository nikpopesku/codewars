#include <unordered_set>

#include "../cw_compat.hpp"

using namespace std;

struct Image {
    unsigned *pixels;
    unsigned width, height;

    unordered_set<unsigned> filter(unordered_set<unsigned> &s) {
        vector<unsigned> for_removal;
        const unsigned mx = width * height;
        const vector<int> directions = {-1 * height, height, -1 * width, width};
        for (auto &elem: s) {
            for (auto &d: directions) {
                if (const int val = elem + d; val >= 0 && val < mx && s.count(val) == 0) {
                    for_removal.push_back(elem);
                }
            }
        }

        for (auto &elem: for_removal) {
            s.erase(elem);
        }
    }

    vector<unsigned> central_pixels(unsigned colour) const {
        unordered_set<unsigned> s;

        for (unsigned row = 0; row < height; ++row) {
            for (unsigned col = 0; col < width; ++col) {
                if (pixels[row * width + col] == colour) {
                    response.insert(row * width + col);
                }
            }
        }

        int step = 1;

        while (true) {
            auto new_s = Image::filter(s);

            if (!new_s.empty()) {
                s = new_s;
                ++step;
            } else {
                break;
            }
        }

        vector<unsigned> response{s.begin(), s.end()};

        return response;
    }
};


vector<unsigned> Image::central_pixels(unsigned colour) const {
}

/* ---------------------------------------------------------------------------------- */
/*                               TESTS                                                */
/* ---------------------------------------------------------------------------------- */

Describe(Centre_of_attention) {
    It(Example_In_The_Picture) {
        Image image({
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
