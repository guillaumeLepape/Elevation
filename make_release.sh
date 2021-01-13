cmake --build build

mkdir Elevation_export
mkdir Elevation_export/build
mkdir Elevation_export/data
mkdir Elevation_export/dataset
mkdir Elevation_export/results

cp build/main Elevation_export/build
cp build/dataset Elevation_export/build
cp -r data Elevation_export
cp -r results Elevation_export
cp -r dataset Elevation_export
