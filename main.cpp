#include <iostream>

// OCCT Modeling API headers
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>

// OCCT STEP Exchange headers
#include <STEPControl_Writer.hxx>
#include <IFSelect_ReturnStatus.hxx>

int main() {
    std::cout << "Initializing Open CASCADE Example..." << std::endl;

    // 1. Define dimensions (Width, Depth, Height)
    Standard_Real dx = 100.0;
    Standard_Real dy = 50.0;
    Standard_Real dz = 30.0;

    // 2. Generate a 3D solid box shape
    std::cout << "Creating a 3D solid box..." << std::endl;
    BRepPrimAPI_MakeBox boxMaker(dx, dy, dz);
    TopoDS_Shape boxShape = boxMaker.Shape();

    // 3. Export the created shape to a STEP file
    std::cout << "Exporting shape to 'minimal_box.stp'..." << std::endl;
    STEPControl_Writer writer;
    
    // Transfer the topology data to the STEP translator
    IFSelect_ReturnStatus transferStatus = writer.Transfer(boxShape, STEPControl_AsIs);
    
    if (transferStatus != IFSelect_RetDone) {
        std::cerr << "Error: Failed to translate shape to STEP format." << std::endl;
        return 1;
    }

    // Write the data to the physical disk file
    IFSelect_ReturnStatus writeStatus = writer.Write("minimal_box.stp");
    
    if (writeStatus == IFSelect_RetDone) {
        std::cout << "Success! File exported successfully." << std::endl;
    } else {
        std::cerr << "Error: Could not write file to disk." << std::endl;
        return 1;
    }

    return 0;
}
