#include <gtest/gtest.h>
#include <memory>
#include "ConceptualExample.cpp"

using namespace ConceptualExample;

TEST(Motivation01Test, CowSee) {
    Motivation01::Cow cow;
    EXPECT_EQ(cow.see(), "cow");
}

TEST(Motivation01Test, CowSay) {
    Motivation01::Cow cow;
    EXPECT_EQ(cow.say(), "moo");
}

TEST(Motivation01Test, PigSee) {
    Motivation01::Pig pig;
    EXPECT_EQ(pig.see(), "pig");
}

TEST(Motivation01Test, PigSay) {
    Motivation01::Pig pig;
    EXPECT_EQ(pig.say(), "oink");
}

TEST(Motivation01Test, DogSee) {
    Motivation01::Dog dog;
    EXPECT_EQ(dog.see(), "dog");
}

TEST(Motivation01Test, DogSay) {
    Motivation01::Dog dog;
    EXPECT_EQ(dog.say(), "woof");
}

TEST(Motivation01Test, SeeAndSay) {
    std::shared_ptr<Motivation01::IAnimal> animal = std::make_shared<Motivation01::Cow>();
    testing::internal::CaptureStdout();
    Motivation01::seeAndSay(animal);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The cow says 'moo' :).\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
