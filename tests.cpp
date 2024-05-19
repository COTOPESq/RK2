#include <gtest/gtest.h>
#include <memory>
#include "ConceptualExample.cpp"

using namespace ConceptualExample::Motivation01;

TEST(Motivation01Test, CowSeeAndSay) {
    std::shared_ptr<IAnimal> cow = std::make_shared<Cow>();
    testing::internal::CaptureStdout();
    seeAndSay(cow);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The cow says 'moo' :).\n");
}

TEST(Motivation01Test, PigSeeAndSay) {
    std::shared_ptr<IAnimal> pig = std::make_shared<Pig>();
    testing::internal::CaptureStdout();
    seeAndSay(pig);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The pig says 'oink' :).\n");
}

TEST(Motivation01Test, DogSeeAndSay) {
    std::shared_ptr<IAnimal> dog = std::make_shared<Dog>();
    testing::internal::CaptureStdout();
    seeAndSay(dog);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The dog says 'woof' :).\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
