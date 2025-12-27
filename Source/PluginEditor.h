/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MIDIpluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MIDIpluginAudioProcessorEditor (MIDIpluginAudioProcessor&);
    ~MIDIpluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MIDIpluginAudioProcessor& audioProcessor;
    juce::LookAndFeel_V4 otherLookAndFeel; 
    juce::Slider midiVolume; // [1]
    juce::Slider dial2;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDIpluginAudioProcessorEditor)
};
