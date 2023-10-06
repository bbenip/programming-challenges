#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

class Directory {
  string name = "";
  Directory* parentDirectory = nullptr;

  unordered_map<string, int> files;
  unordered_map<string, Directory *> subdirectories;

  int totalFileSize = -1;
  int directorySize = -1;

  int getTotalFileSize() {
    if (totalFileSize != -1) {
      return totalFileSize;
    }

    int size = 0;

    for (auto& file : files) {
      size += file.second;
    }

    totalFileSize = size;

    return totalFileSize;
  }

  public:
    Directory(string name = "/", Directory* parentDirectory = nullptr)
      : name{name}, parentDirectory{parentDirectory} {}

    ~Directory() {
      for (auto& subdirectory : subdirectories) {
        delete subdirectory.second;
      }
    }

    void addFile(string fileName, int fileSize) {
      files[fileName] = fileSize;
    }

    void addSubdirectory(string name) {
      subdirectories[name] = new Directory(name, this);
    }

    Directory* getParentDirectory() {
      return parentDirectory;
    }

    Directory* getSubdirectory(string name) {
      return subdirectories[name];
    }

    unordered_map<string, Directory*>& getSubdirectories() {
      return subdirectories;
    }

    int getDirectorySize() {
      if (directorySize != -1) {
        return directorySize;
      }

      int size = getTotalFileSize();

      for (auto& subdirectory : subdirectories) {
        size += (subdirectory.second)->getDirectorySize();
      }

      directorySize = size;

      return directorySize;
    }
};

int main() {
  const int TOTAL_DISK_SPACE = 7E7;
  const int REQUIRED_DISK_SPACE = 3E7;

  Directory baseDirectory;
  Directory* currentDirectory = &baseDirectory;

  ifstream file("input.txt");
  string line = "";

  while (getline(file, line)) {
    istringstream ss(line);
    string marker = "";

    ss >> marker;

    const bool isCommand = (marker == "$");

    if (isCommand) {
      string command = "";
      ss >> command;

      if (command == "cd") {
        string path = "";
        ss >> path;

        if (path == "..") {
          currentDirectory = currentDirectory->getParentDirectory();
        } else {
          currentDirectory->addSubdirectory(path);
          currentDirectory = currentDirectory->getSubdirectory(path);
        }
      }
    } else {
      if (marker == "dir") {
        continue;
      }

      int fileSize = stoi(marker);

      string fileName = "";
      ss >> fileName;

      currentDirectory->addFile(fileName, fileSize);
    }
  }

  const int currentDiskUsage = baseDirectory.getDirectorySize();
  const int maximumAllowableDiskUsage = TOTAL_DISK_SPACE - REQUIRED_DISK_SPACE;
  const int minimumDirectorySize = currentDiskUsage - maximumAllowableDiskUsage;

  int smallestCandidateDirectorySize = currentDiskUsage;

  if (minimumDirectorySize <= 0) {
    smallestCandidateDirectorySize = 0;
  }

  queue<Directory*> directories;
  directories.push(&baseDirectory);

  while (!directories.empty()) {
    Directory* directory = directories.front();
    directories.pop();

    int directorySize = directory->getDirectorySize();

    if (
      directorySize >= minimumDirectorySize
      && directorySize < smallestCandidateDirectorySize
    ) {
      smallestCandidateDirectorySize = directorySize;
    }

    const auto& subdirectories = directory->getSubdirectories();
    for (const auto& subdirectory : subdirectories) {
      directories.push(subdirectory.second);
    }
  }

  cout
    << "Smallest candidate directory size: "
    << smallestCandidateDirectorySize
    << endl;
}
