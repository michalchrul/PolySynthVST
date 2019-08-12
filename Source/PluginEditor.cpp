/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider.setRange(0.1f, 5000.0f);
	attackSlider.setValue(0.1f);
//	attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
	attackSlider.addListener(this);
	addAndMakeVisible(&attackSlider);


	releaseSlider.setSliderStyle(Slider::LinearVertical);
	releaseSlider.setRange(0.1f, 5000.0f);
	releaseSlider.setValue(0.1f);
	//	releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
	releaseSlider.addListener(this);
	addAndMakeVisible(&releaseSlider);


	attackTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
	releaseTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
	
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
	attackSlider.setBounds(10, 10, 40, 50);
	releaseSlider.setBounds(60, 10, 40, 50);
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if (slider == &attackSlider)
	{
		processor.attackTime = attackSlider.getValue();
	}
	if (slider == &releaseSlider)
	{
		processor.releaseTime = releaseSlider.getValue();
	}
}