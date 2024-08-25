#include <iostream>
#include <vector>

#ifndef __SEQUENCE__
#define __SEQUENCE__

template <class  Key = int> class Sequence {
 public:
    virtual bool search(const Key& k) const = 0;
    virtual bool insert(const Key& k) = 0;
    virtual void Print() = 0;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Key = int> class DynamicSequence: public Sequence<Key> {
    public:
        bool search(const Key& k) const {
            for (int i = 0; i < Container_.size(); ++i) {
                if (Container_[i] == k) {
                    return true;
                }
            }
            return false;
        }
        bool insert(const Key& k) {
            std::cout << "~ Insertando elemento" << std::endl;
            Container_.emplace_back(k);
            return true;
        }
        void Print() {
            std::cout << Container_.size() << " | ";
            for (int i = 0; i < Container_.size(); ++i) {
                std::cout << Container_[i] << "  ";
            }
            std::cout << "\n";
        }
    protected:
    std::vector<Key> Container_;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Key = int> class StaticSequence: public Sequence<Key> {
    public:
        StaticSequence (const int kBlock_size) : block_size_(kBlock_size) {} 

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

        bool IsFull() const { return Container_.size() == block_size_;}

        void Print() {
            std::cout << Container_.size() << " | ";
            for (int i = 0; i < Container_.size(); ++i) {
                std::cout << Container_[i] << "  ";
            }
            if (IsFull()) std::cout << "   X";
            std::cout << "\n";
        }
        
    protected:
        std::vector<Key> Container_;
        int block_size_{1};
};

#endif