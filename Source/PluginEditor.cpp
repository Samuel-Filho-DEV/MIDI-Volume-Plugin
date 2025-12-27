/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MIDIpluginAudioProcessorEditor::MIDIpluginAudioProcessorEditor (MIDIpluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need
    //Set the Plugin size
    setSize (200, 200);

    //Slider parameters
    //midiVolume.setSliderStyle(juce::Slider::LinearBarVertical);
    //midiVolume.setRange(0.0, 127.0, 1.0);
    //midiVolume.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    //midiVolume.setPopupDisplayEnabled(true, false, this);
    //midiVolume.setTextValueSuffix(" Volume");
    //midiVolume.setValue(1.0);
    //Add slider to the editor
    //addAndMakeVisible(&midiVolume);

    //Rotary Slider(Knob)
    dial2.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    dial2.setRange(0.0, 127.0, 1.0);
    //dial2.setColour(juce::Slider::ColourIds);
    addAndMakeVisible(&dial2);


}

MIDIpluginAudioProcessorEditor::~MIDIpluginAudioProcessorEditor()
{
}

//==============================================================================
void MIDIpluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::darkgrey);

    //Set BG color to White
    g.setColour (juce::Colours::white);
    //Set drawing color to black
    g.setColour(juce::Colours::black);
    //Set font size
    g.setFont (juce::FontOptions (15.0f));
    //Draw text to the Screen
    g.drawFittedText ("MIDI Volume", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void MIDIpluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // Slider position
    //midiVolume.setBounds(40, 30, 20, getHeight() - 60);
    
    // Set slider position and size (x, y, width, height)
    //dial2.setBounds(getLocalBounds());
    dial2.setBounds(50, 50, 20, getHeight() - 60);
    dial2.setSize(100, 100);
}

