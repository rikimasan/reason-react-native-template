/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/facebook/react-native/blob/724fe11472cb874ce89657b2c3e7842feff04205/template/App.js
 * With a few tweaks
 */
open ReactNative;

module Colors = {
  type colors;

  [@mel.module "react-native/Libraries/NewAppScreen"]
  external colors: colors = "Colors";

  [@mel.get] external primary: colors => string = "primary";
  [@mel.get] external white: colors => string = "white";
  [@mel.get] external lighter: colors => string = "lighter";
  [@mel.get] external light: colors => string = "light";
  [@mel.get] external dark: colors => string = "dark";
  [@mel.get] external darker: colors => string = "darker";
  [@mel.get] external black: colors => string = "black";
  let primary = primary(colors);
  let white = white(colors);
  let lighter = lighter(colors);
  let light = light(colors);
  let dark = dark(colors);
  let darker = darker(colors);
  let black = black(colors);
};

module DebugInstructions = {
  [@react.component] [@mel.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "DebugInstructions";
};

module Header = {
  [@react.component] [@mel.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "Header";
};

module LearnMoreLinks = {
  [@react.component] [@mel.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "LearnMoreLinks";
};

module ReloadInstructions = {
  [@react.component] [@mel.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "ReloadInstructions";
};

/*
 Here is StyleSheet that is using Style module to define styles for your components
 The main different with JavaScript components you may encounter in React Native
 is the fact that they **must** be defined before being referenced
 (so before actual component definitions)
 More at https://reason-react-native.github.io/en/docs/apis/Style/
 */

module Styles = {
  let sectionContainer =
    Style.style(
      ~marginTop=Style.dp(32.),
      ~paddingHorizontal=Style.dp(24.),
      (),
    );

  let sectionTitle = isDarkMode =>
    (isDarkMode ? Colors.white : Colors.black)
    |> (color => Style.style(~fontSize=24., ~fontWeight=`_600, ~color, ()));
  let sectionDescription = isDarkMode =>
    (isDarkMode ? Colors.white : Colors.black)
    |> (
      color =>
        Style.style(
          ~color,
          ~marginTop=Style.dp(8.),
          ~fontSize=18.,
          ~fontWeight=`_400,
          (),
        )
    );
  let highlight = Style.style(~fontWeight=`_700, ());
};

module Section = {
  let isDarkMode =
    Appearance.useColorScheme()
    |> Js.Null.toOption
    |> Option.fold(~none=`light, ~some=a => a)
    |> (
      fun
      | `dark => true
      | `light => false
    );
  [@react.component]
  let make = (~title: string, ~children) =>
    <View style=Styles.sectionContainer>
      <Text style={isDarkMode |> Styles.sectionTitle}>
        {title |> React.string}
      </Text>
      <Text style={isDarkMode |> Styles.sectionDescription}> children </Text>
    </View>;
};

[@react.component]
let app = () => {
  let isDarkMode =
    Appearance.useColorScheme()
    |> Js.Null.toOption
    |> Option.fold(~none=`light, ~some=a => a)
    |> (
      fun
      | `dark => true
      | `light => false
    );
  let backgroundColor = isDarkMode ? Colors.darker : Colors.lighter;
  let backgroundStyle = Style.style(~backgroundColor, ());

  <SafeAreaView style=backgroundStyle>
    <StatusBar
      barStyle={isDarkMode ? `lightContent : `darkContent}
      backgroundColor
    />
    <ScrollView
      contentInsetAdjustmentBehavior=`automatic style=backgroundStyle>
      <Header />
      <View
        style={Style.style(
          ~backgroundColor=isDarkMode ? Colors.black : Colors.white,
          (),
        )}>
        <Section title="Step One">
          {"Edit " |> React.string}
          <Text style=Styles.highlight> {"App.tsx" |> React.string} </Text>
          {" to change this screen and then come back to see your edits."
           |> React.string}
        </Section>
        <Section title="See Your Changes"> <ReloadInstructions /> </Section>
        <Section title="Debug"> <DebugInstructions /> </Section>
        <Section title="Learn More">
          {"Read the docs to discover what to do next:" |> React.string}
        </Section>
        <LearnMoreLinks />
      </View>
    </ScrollView>
  </SafeAreaView>;
};
