B0 template based on Geant4.11.2 example/B1 from Brooks Hartsock (brookshartsock@gmail.com)

Notably, here are the changes if you're curious:
  Removed exampleB1.in/.out, run1/2.mac, added batch.mac
  Simplified DetectorConstruction by removing anything but the world and a simple box
  PrimaryGeneratorAction will default to isoptropically generating particles at 0,0,0
  RunAction was simplified, only outputting the edep average (functional for nThreads > 1) and rms (not functional for nThread > 1, idk man)
  init_vis.mac will run nThreads = 1 instead of the default... being as many as available (WHY)
  Removed ugly logo/scale/stuff in vis.mac

If you want to change the project prefix from "B0" that's too damn bad, do it yourself!
  or run newB0.bash alongside the "source" file. You will have to "chmod +x newB0.bash" and "./newB0.bash projPrefix"
  where "projPrefix" will replace "B0" in every (important) file. 
  CAUTION!!! THIS SCRIPT WILL ATTEMPT TO OVERRITE ANY FILE IN "source"
