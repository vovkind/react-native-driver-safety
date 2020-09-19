import { NativeModules } from 'react-native';

type DriverSafetyType = {
  multiply(a: number, b: number): Promise<number>;
  enable(a:  string): any;
};

const { DriverSafety } = NativeModules;

export default DriverSafety as DriverSafetyType;
