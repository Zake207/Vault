#include <iostream>
#include <vector>
#include <fstream>

#include "../Nif/Nif.h"

#ifndef __SEQUENCE__
#define __SEQUENCE__

template <class  Key = int> class Sequence {
 public:
    virtual bool search(const Key& k) const = 0;
    virtual bool insert(const Key& k) = 0;
    virtual void Print() = 0;
    virtual Key& operator[](const int p) = 0;
    virtual void swap(int i, int j) = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Key = int> class StaticSequence: public Sequence<Key> {
    public:
        StaticSequence (const int kBlock_size, bool random = false) : block_size_(kBlock_size) {
            if (random) {
                Container_.reserve(block_size_);
                for (int i = 0; i < block_size_; ++i) {
                    Container_.emplace_back(Nif());
                }
            } else {
                Container_.reserve(block_size_);
                Key value;
                std::cout << "Introduce " << block_size_ << " elements: " << std::endl;
                for (int i = 0; i < block_size_; ++i) {
                    std::cin >> value;
                    Container_.emplace_back(value);
                }
            }
        }

        StaticSequence (const int kSize, const std::string& file) : block_size_(kSize) {
            Container_.reserve(kSize);
            std::ifstream f(file);
            if (f.is_open()) {
                Key value;
                while (f >> value) {
                    Container_.emplace_back(value);
                }
            }
        }

        bool search(const Key& k) const {
            for (int i = 0; i < Container_.size(); ++i) {
                if (Container_[i] == k) {
                    return true;
                }
            }
            return false;
        }
        bool insert(const Key& k) {
            if(IsFull()) {
                return false;
            }
            std::cout << "~ Insertando elemento." << std::endl;
            Container_.emplace_back(k);
            return true;
        }

        void swap(int i, int j) {
            Key temp = Container_[i];
            Container_[i] = Container_[j];
            Container_[j] = temp;
        }

        int GetSize() const { return Container_.size(); }

        bool IsFull() const { return Container_.size() == block_size_;}

        void Print() {
            std::cout << " | ";
            for (int i = 0; i < Container_.size(); ++i) {
                std::cout << Container_[i] << " ";
            }
            std::cout << "| " << std::endl;
        }

        Key& operator[](const int p) {
            return Container_[p];
        }
        
    protected:
        std::vector<Key> Container_;
        int block_size_{1};
};

#endif