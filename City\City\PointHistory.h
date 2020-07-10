/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

    /** Iterator that iterates over the points */
    class Iter
    {
    public:
        /** Constructor
         * \param history The history clicks we are iterating over
         * \param someLists number of lists
         * \param index the index of the iterator
         */
        Iter(CPointHistory* history, int someLists, int index) : mMouseHistory(history), mPos(someLists), mMouseIndex(index) {}

        /** Test for end of the iterator
        * \param other A parameter for an other variable
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos || mMouseIndex != other.mMouseIndex;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const { return mMouseHistory->mPotatoLists[mPos][mMouseIndex]; }
        

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;

            if (mPos >= NumLists)
            {
                mPos = 0;
                mMouseIndex++;
            }
            return *this;
        }


    private:
        CPointHistory* mMouseHistory;   ///< The mouse history we are iterating over
        int mPos;       ///< Position in the collection
        size_t mMouseIndex; ///< index of mouse
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0,0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mCurrentList, mPotatoLists[mCurrentList].size()); }


protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

