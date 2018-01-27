#include "../src/HBT_correlation.h"
#include "gtest/gtest.h"

namespace {
// Tests the Glauber class

TEST(HBT_correlation, DefaultConstructor) {
    ParameterReader *paraRdr = new ParameterReader;
    paraRdr->readFromFile("parameters.dat");
    paraRdr->setVal("run_mode", 1);
    string path="test_gzip_reader";
    particleSamples particle_list(paraRdr, path);
        
    HBT_correlation test(paraRdr, path, &particle_list);
    EXPECT_EQ(0, 0);
}

TEST(HBT_correlation, calculate_flow_event_plane_angle) {
    ParameterReader *paraRdr = new ParameterReader;
    paraRdr->readFromFile("parameters.dat");
    paraRdr->setVal("run_mode", 1);
    string path="test_gzip_reader";
    particleSamples particle_list(paraRdr, path);
    particle_list.read_in_particle_samples();
        
    HBT_correlation test(paraRdr, path, &particle_list);
    test.calculate_flow_event_plane_angle(1);
    double psi_ref = test.get_psi_ref();
    EXPECT_NEAR(psi_ref, -1.6751628499713109, 1e-8);

    test.calculate_flow_event_plane_angle(2);
    psi_ref = test.get_psi_ref();
    EXPECT_NEAR(psi_ref, -0.85236384292521539, 1e-8);
    
    test.calculate_flow_event_plane_angle(3);
    psi_ref = test.get_psi_ref();
    EXPECT_NEAR(psi_ref, 0.06674083818478263, 1e-8);
}

}  // namespace
