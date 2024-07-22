/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/react-native-community/template/blob/0.75.0-rc.5/template/App.tsx
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
  [@react.component]
  let make = (~title: string, ~children) => {
    let isDarkMode =
      Hooks.useColorScheme()
      |> Option.fold(~none=`light, ~some=a => a)
      |> (
        fun
        | `dark => true
        | `light => false
      );
    <View style=Styles.sectionContainer>
      <Text style={isDarkMode |> Styles.sectionTitle}>
        {title |> React.string}
      </Text>
      <Text style={isDarkMode |> Styles.sectionDescription}> children </Text>
    </View>;
  };
};

[@react.component]
let app = () => {
  let isDarkMode =
    Hooks.useColorScheme()
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
