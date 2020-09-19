import { NativeModules } from 'react-native';

type DriverSafetyType = {
  enable(a:  string): any;
};

const { DriverSafety } = NativeModules;

export default DriverSafety as DriverSafetyType;
