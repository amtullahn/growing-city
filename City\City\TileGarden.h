/**
 * \file TileGarden.h
 *
 * \author Amtullah Naalwala
 *
 * Tend the garden type after adding a new Garden tile type 
 */

#pragma once
#include "Tile.h"
#include "TileVisitor.h"


/**
 * A garden tile
 */
class CTileGarden :
	public CTile
{
public:
    CTileGarden(CCity* city);

    ///  Default constructor (disabled)
    CTileGarden() = delete;

    ///  Copy constructor (disabled)
    CTileGarden(const CTileGarden&) = delete;

    ~CTileGarden();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed);
    
    /// Accepts a garden tile and resets it to the initial state 
    /// \param garden a garden tile
    void Prune(CTileGarden *garden);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override {visitor-> VisitGarden(this);};
   

    /// The supported pruning states
    enum class PruningStates { Pruned, Overgrown1, Overgrown2, Overgrown3, Overgrown4 };

private:

    /// Time elapsed since pruning
    double mSincePruning = 0;

    /// The current garden pruning state
    PruningStates mPruningState = PruningStates::Pruned;
};

