#include <iostream>
#include <stdlib.h>

// OCCT main handle
#include "Standard_Handle.hxx"


// OCCT STEP Exchange headers
#include <STEPControl_Writer.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include "MakeBottle.cpp"

namespace occ {
	template <class T>
	using handle = opencascade::handle<T>;
}

int main(int argc, char* argv[]) {
    std::cout << "Initializing Open CASCADE Example..." << std::endl;
    if (argc != 3){
	std::cout << "Please supply 3 floats for the bottle dimensions" << std::endl;
	}

    TopoDS_Shape bottleShape = MakeBottle(atof(argv[1]), atof(argv[2]), atof(argv[3]));

    // 3. Export the created shape to a STEP file
    std::cout << "Exporting shape to 'OCCT_Bottle.stp'..." << std::endl;
    STEPControl_Writer writer;
    
    // Transfer the topology data to the STEP translator
    IFSelect_ReturnStatus transferStatus = writer.Transfer(bottleShape, STEPControl_AsIs);
    
    if (transferStatus != IFSelect_RetDone) {
        std::cerr << "Error: Failed to translate shape to STEP format." << std::endl;
        return 1;
    }

    // Write the data to the physical disk file
    IFSelect_ReturnStatus writeStatus = writer.Write("OCCT_Bottle.stp");
    
    if (writeStatus == IFSelect_RetDone) {
        std::cout << "Success! File exported successfully." << std::endl;
    } else {
        std::cerr << "Error: Could not write file to disk." << std::endl;
        return 1;
    }

    return 0;
}
