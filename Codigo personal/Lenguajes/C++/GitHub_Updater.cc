#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("git pull");
    system("git add .");
    system("git commit -m 'Obsidian-update'");
    system("git push");
    return 0;
}