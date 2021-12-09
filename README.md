# GEM to CellRanger

Given a STOmics GEM file, converts to CellRanger output, and a spatial file storing barcodes, x positions and y positions.


## Installation
```
git clone https://github.com/harrymueller/GEM_to_CellRanger.git
cd GEM_to_CellRanger/src
make
```

## Usage
```
Usage: GEMtoCellRanger [OPTIONS] -i [INPUT] -o [OUTPUT] 
Converts a GEM file to a CellRanger format with a spatial file.

  -i filename    GEM file
  -o dir         Specifies the output dir
  -b binsize     Size of bins to use [default=10]
  -v             Verbose
  -h             Help
```

### Example Usage
```
./GEMtoSlideSeq -i data/data-full.gem -o out -v -b 100 -l tongue4
```