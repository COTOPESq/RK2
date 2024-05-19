#include <gtest/gtest.h>
#include <memory>
#include "ConceptualExample.cpp"

using namespace ConceptualExample;

TEST(Motivation01Test, CowSee) {
    Cow cow;
    EXPECT_EQ(cow.see(), "cow");
}

TEST(Motivation01Test, CowSay) {
    Cow cow;
    EXPECT_EQ(cow.say(), "moo");
}

TEST(Motivation01Test, PigSee) {
    Pig pig;
    EXPECT_EQ(pig.see(), "pig");
}

TEST(Motivation01Test, PigSay) {
    Pig pig;
    EXPECT_EQ(pig.say(), "oink");
}

TEST(Motivation01Test, DogSee) {
    Dog dog;
    EXPECT_EQ(dog.see(), "dog");
}

TEST(Motivation01Test, DogSay) {
    Dog dog;
    EXPECT_EQ(dog.say(), "woof");
}

TEST(Motivation01Test, SeeAndSay) {
    std::shared_ptr<IAnimal> animal = std::make_shared<Cow>();
    testing::internal::CaptureStdout();
    seeAndSay(animal);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The cow says 'moo' :).\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
