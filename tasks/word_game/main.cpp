/*
*  Copyright (c) 2014 Evgeny Proydakov <lord.tiran@gmail.com>
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*  THE SOFTWARE.
*/

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

#include <common.h>
#include <word_game_app.h>

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");

    if (argc != 3)
    {
        std::cerr << "Usage: task_word_game task_file_path dict_file_path" << std::endl;
        return EXIT_FAILURE;
    }
    const std::string task_file_path(argv[1]);
    const std::string dict_file_path(argv[2]);

    WordGameApp app;

    data_t solution;
    app.solve(task_file_path, dict_file_path, solution);

    if (solution.empty()) {
        std::cerr << "solution not found" << std::endl;
        return EXIT_FAILURE;
    }

    for (auto &el : solution) {
        std::wcout << el << "\n";
    }

    return EXIT_SUCCESS;
}
