(lang dune 3.15)

(using melange 0.1)

(source
 (github rikimasan/reason-react-native-template))

(license MIT)

(maintainers "Kian Masri")

(authors "Kian Masri")

(homepage https://github.com/rikimasan/reason-react-native-template)

(bug_reports
 https://github.com/rikimasan/reason-react-native-template/issues)

(name reason-react-native-template)

(package
 (allow_empty)
 (name reason-react-native-template)
 (synopsis "Reason React Native Template")
 (description "Reason React Native Template")
 (depends
  (melange
   (and
    (>= 3.0.0)
    (< 5.0.0)))
  (ocaml
   (>= 5.1.0))
  (reason
   (>= 3.10.0))
  opam-check-npm-deps
  (reason-react
   (= 0.14.1))
  reason-react-native))

(generate_opam_files)
